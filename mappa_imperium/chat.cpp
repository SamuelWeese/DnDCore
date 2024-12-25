#include <SFML/Graphics.hpp>
#include <SFML/Network.hpp>
#include <iostream>
#include <string>
#include <thread>
#include <vector>
#include <mutex>

std::mutex chatMutex;
std::vector<std::string> chatMessages;

void receiveMessages(sf::TcpSocket& socket) {
    char buffer[1024];
    std::size_t received;
    while (true) {
        if (socket.receive(buffer, sizeof(buffer), received) == sf::Socket::Done) {
            std::lock_guard<std::mutex> lock(chatMutex);
            chatMessages.push_back(std::string(buffer, received));
        }
    }
}

int main() {
    // Network setup
    sf::TcpSocket socket;
    sf::TcpListener listener;

    std::cout << "Host (h) or Join (j)? ";
    char choice;
    std::cin >> choice;

    if (choice == 'h') {
        listener.listen(53000);
        listener.accept(socket);
        std::cout << "Client connected!" << std::endl;
    } else if (choice == 'j') {
        sf::IpAddress serverIP;
        std::cout << "Enter server IP: ";
        std::cin >> serverIP;
        if (socket.connect(serverIP, 53000) != sf::Socket::Done) {
            std::cerr << "Could not connect to server!" << std::endl;
            return 1;
        }
        std::cout << "Connected to server!" << std::endl;
    }

    // Detach a thread to handle incoming messages
    std::thread receiverThread(receiveMessages, std::ref(socket));
    receiverThread.detach();

    // SFML window setup
    sf::RenderWindow window(sf::VideoMode(800, 600), "Chat Box UI");
    sf::Font font;
    if (!font.loadFromFile("arial.ttf")) {
        std::cerr << "Could not load font!" << std::endl;
        return 1;
    }

    std::string inputBuffer;
    sf::Text chatDisplay;
    sf::Text inputDisplay;

    chatDisplay.setFont(font);
    chatDisplay.setCharacterSize(20);
    chatDisplay.setFillColor(sf::Color::White);
    chatDisplay.setPosition(10, 10);

    inputDisplay.setFont(font);
    inputDisplay.setCharacterSize(20);
    inputDisplay.setFillColor(sf::Color::Green);
    inputDisplay.setPosition(10, 550);

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }

            if (event.type == sf::Event::TextEntered) {
                if (event.text.unicode == '\b' && !inputBuffer.empty()) {
                    inputBuffer.pop_back(); // Handle backspace
                } else if (event.text.unicode == '\r') {
                    if (!inputBuffer.empty()) {
                        // Send the message
                        socket.send(inputBuffer.c_str(), inputBuffer.size());
                        {
                            std::lock_guard<std::mutex> lock(chatMutex);
                            chatMessages.push_back("You: " + inputBuffer);
                        }
                        inputBuffer.clear();
                    }
                } else if (event.text.unicode < 128) {
                    inputBuffer += static_cast<char>(event.text.unicode);
                }
            }
        }

        // Update chat display
        {
            std::lock_guard<std::mutex> lock(chatMutex);
            std::string allMessages;
            for (const auto& message : chatMessages) {
                allMessages += message + "\n";
            }
            chatDisplay.setString(allMessages);
        }

        inputDisplay.setString("> " + inputBuffer);

        // Render
        window.clear();
        window.draw(chatDisplay);
        window.draw(inputDisplay);
        window.display();
    }

    return 0;
}
