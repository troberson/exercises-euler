#pragma once

#include <euler/utils/template_types.hpp> // utils::IsIntegral

#include <algorithm> // std::generate
#include <vector> // std::vector


namespace euler::utils
{

template <typename T, typename = IsIntegral<T>>
class TriangleNumberGenerator
{

private:
    // Store results in a list
    std::vector<T> triangles {0};

public:
    /**
     * Get the Nth triangle number
     *
     * @param n the triangle number to get (starting from T[1] = 1)
     * @returns a triangle number
     */
    T get_nth(int n)
    {
        if (n < 1)
        {
            return 0;
        }

        try {
            return triangles.at(n);
        } catch(...) {
            return triangles.emplace_back(get_nth(n - 1) + n);
        }
    }


    /**
     * Get the Nth triangle number
     *
     * Convenience function for get_nth()
     *
     * @param n the triangle number to get (starting from T[1] = 1)
     * @returns a triangle number
     */
    T operator[] (int n)
    {
        return get_nth(n);
    }


    /**
     * Get the first N triangle numbers
     *
     * @param n how many triangle numbers to get (min: 0)
     * @param start the starting position (default: T[1] = 1, min: 0)
     * @returns a list of triangle numbers
     */
     std::vector<T> get_first_n(int n, int start = 1)
    {
        // Parameter checks
        if (n <= 0)
        {
            return std::vector<T> {};
        }

        if (start < 0)
        {
            start = 0;
        }

        // Get the nth triangle number to fill the list
        get_nth(n);

        // Return the first n elements of the list
        return std::vector<T>(triangles.begin() + start, triangles.begin() + n + 1);
    }
};

} // end namespace euler::utils
