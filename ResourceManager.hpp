#pragma once

#include "Resource.hpp"

class ResourceManager
{
private:
    std::unique_ptr< Resource > resourcePtr;

public:
    ResourceManager() : resourcePtr(std::make_unique< Resource >()) {}

    double get() const
    {
        return resourcePtr->get(); // Wywo³anie metody get() z obiektu Resource
    }

    // Konstruktor kopiuj¹cy
    ResourceManager(const ResourceManager& other)
        : resourcePtr(std::make_unique< Resource >(*other.resourcePtr))
    {}

    // Operator przypisania kopiuj¹cego
    ResourceManager& operator=(const ResourceManager& other)
    {
        if (this != &other) {
            resourcePtr = std::make_unique< Resource >(*other.resourcePtr);
        }
        return *this;
    }

    // Domyœlny destruktor
    ~ResourceManager() = default;
};
