#include "EventManager.hpp"

#include "GraphicsManager.hpp"
#include <iostream>
#include <string>

int EventManager::next_uid = 0;

EventManager::Event::Event() {
}

EventManager::Event::Event(sf::Event& ev) : event(ev) {
}

EventManager::EventType EventManager::Event::getType() const {
    switch (event.type) {
    case sf::Event::EventType::KeyPressed:
        return EventType::KeyPressed;
    case sf::Event::EventType::KeyReleased:
        return EventType::KeyReleased;
    case sf::Event::EventType::TextEntered:
        return EventType::TextEntered;
    case sf::Event::EventType::MouseWheelScrolled:

        if (event.mouseWheelScroll.delta > 0)
            return EventType::MouseWheelScrolledUp;
        else
            return EventType::MouseWheelScrolledDown;

    case sf::Event::EventType::MouseButtonPressed:
        return EventType::MouseButtonPressed;
    case sf::Event::EventType::MouseButtonReleased:
        return EventType::MouseButtonReleased;
    default:
        return EventType::Other;
    }
}

EventManager::MouseButton EventManager::Event::getMouseButton() const {
    return static_cast<EventManager::MouseButton>(event.mouseButton.button);
}

EventManager::Key EventManager::Event::getKey() const {
    return static_cast<EventManager::Key>(event.key.code);
}

char EventManager::Event::getChar() const {
    if (event.text.unicode < 128)
        return static_cast<char>(event.text.unicode);
    else
        return ' ';
}

EventManager::EventManager(GraphicsManager& graphics)
    : graphics_(graphics), lastElapsedTime(sf::Time::Zero) {
}

GraphicsManager& EventManager::getGraphicsManager() const {
    return graphics_;
}

int EventManager::addKeyboardListener(std::function<void(Event)> callback) {
    keyboard_callbacks[next_uid] = callback;
    return next_uid++;
}

void EventManager::removeKeyboardListener(int id) {
    keyboard_callbacks.erase(id);
}

int EventManager::addMouseListener(std::function<void(Event)> callback) {
    mouse_callbacks[next_uid] = callback;
    return next_uid++;
}

void EventManager::removeMouseListener(int id) {
    mouse_callbacks.erase(id);
}

void EventManager::processEvents() {
    lastElapsedTime = clock.restart();

    sf::Event event;

    while (graphics_.getWindow()->pollEvent(event)) {

        Event event_obj = Event(event);

        if (event_obj.getType() == EventType::KeyPressed
            || event_obj.getType() == EventType::KeyReleased
            || event_obj.getType() == EventType::TextEntered) {
            for (auto it = keyboard_callbacks.begin();
                 it != keyboard_callbacks.end();
                /**/) {
                auto current = it++;
                current->second(event_obj);
            }
        } else if (event_obj.getType() != EventType::Other) {
            for (auto it = mouse_callbacks.begin(); it != mouse_callbacks.end();
                /**/) {
                auto current = it++;
                current->second(event_obj);
            }
        }
    }
}

float EventManager::getLastElapsedTime() const {
    return lastElapsedTime.asSeconds();
}