#pragma once
#include <ostream>
#include <iostream>

class Matrix{
    private:
        int rows, columns;
        double** matrix;
    public:
        Matrix(int nRows, int nColumns);
        Matrix() 
            :rows{0},columns{0},matrix{nullptr}{}
        explicit Matrix(int nRows);
        ~Matrix();
        Matrix(const Matrix& rhs);
        Matrix& operator=(const Matrix& m);
        double get (int row, int col) const {return matrix[row-1][col-1];}
        void set(int row, int col, double value) {matrix[row-1][col-1] = value;}
        //double operator[](int c) {return matrix[][c];} -hvordan skal man gjøre dette?
        int getRows() const {return rows;}
        int getColumns() const {return columns;}
        bool isValid() const;
        friend std::ostream& operator<<(std::ostream& os,const Matrix& m);
        Matrix& operator+=(const Matrix& m);
        Matrix& operator+(const Matrix& m);            
};









