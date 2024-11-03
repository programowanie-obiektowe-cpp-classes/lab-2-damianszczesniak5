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
        return resourcePtr->get(); // Wywo�anie metody get() z obiektu Resource
    }

    // Konstruktor kopiuj�cy
    ResourceManager(const ResourceManager& other)
        : resourcePtr(std::make_unique< Resource >(*other.resourcePtr))
    {}

    // Operator przypisania kopiuj�cego
    ResourceManager& operator=(const ResourceManager& other)
    {
        if (this != &other) {
            resourcePtr = std::make_unique< Resource >(*other.resourcePtr);
        }
        return *this;
    }

    // Domy�lny destruktor
    ~ResourceManager() = default;
};
