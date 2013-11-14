/*
 *  Utilities.h
 *  
 *
 *  Created by John Carlyle on 3/29/09.
 *  Utility classes
 *
 */

#ifndef UTILITIES_H
#define UTILITIES_H

#include <vector>

class StateStack    {
private:
    std::vector<int> stack;
public:
    void pushState  ( int s )   { stack.push_back( s ); }
    void popState   ( int n )   { for ( int i = 0; i < n; i++ ) popState(); }
    void popState   ( )         { stack.pop_back(); }
    int  getState   ( )         { return stack[stack.size() - 1]; }
};

template <class T>
class Matrix    {
private:
    int width, height;
    T* array;
public:
    Matrix          ( )                         { width = 2; height = 2; array = new T[width * height]; }
    Matrix          ( int _width, int _height ) { width = _width; height = _height; array = new T[width * height]; }
    ~Matrix         ( )                         { delete [] array; }
    void put        ( T value, int x, int y )   { array[width * y + x] = value; }
    T* get          ( int x, int y )            { return &array[width * y + x]; }
    int getWidth    ( )                         { return width; }
    int getHeight   ( )                         { return height; }
};

#endif