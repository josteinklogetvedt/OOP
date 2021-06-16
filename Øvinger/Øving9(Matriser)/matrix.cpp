#include "matrix.h"

 Matrix::Matrix(int nRows, int nColumns)
            :rows{nRows},columns{nColumns}, matrix{new double*[nRows]}{
                for (int i=0; i<nRows; ++i){
                    matrix[i]=new double[nColumns];
                    for (int j=0; j<nColumns; ++j){
                        matrix[i][j] = 0;
                    }
                }
            }

Matrix::Matrix(int nRows) : Matrix(nRows,nRows){
    for (int i=0; i<nRows; ++i){
        matrix[i][i] = 1;
    }
}
Matrix::~Matrix(){
    for (int i = 0; i<rows; ++i){
        delete[] matrix[i];
    }
    delete[] matrix;
}

bool Matrix::isValid() const{
    if (matrix==nullptr || rows<=0 || columns<=0) {return false;}
    else {return true;}
}

std::ostream& operator<<(std::ostream& os,const Matrix& m){
    if (!m.isValid()) {
        os << "Ikke gyldig matrise\n"; 
        return os;
    }
    else{
        for (int i=0; i<m.getRows(); ++i){
            for (int j=0; j<m.getColumns(); ++j){
                os << m.get(i+1,j+1) << " ";
            }
            os << std::endl;
        }
        return os;
    }
}

//Copy constructor:
Matrix::Matrix(const Matrix& rhs)
    :rows{rhs.rows},columns{rhs.columns},matrix{new double*[rhs.rows]}{
        for (int i=0; i<rhs.rows;++i){
            matrix[i] = new double[rhs.columns];
            for (int j=0; j<rhs.columns; ++j){
                matrix[i][j] = rhs.get(i+1,j+1); 
            }
        }
    }

Matrix& Matrix::operator=(const Matrix& m){
    for (int i = 0; i<rows; ++i){
        delete[] matrix[i];
    }
    delete[] matrix;
    rows = m.rows;
    columns = m.columns;
    double** temp = new double*[rows];
    for (int i = 0; i<rows; ++i){
        temp[i] = new double[columns];
        for (int j=0; j<columns; ++j){
            temp[i][j] = m.get(i+1,j+1);
        }
    }
    matrix = temp;
    return *this;
}

//Operator overloading
Matrix& Matrix::operator+=(const Matrix& m){
    if (rows!=m.rows || columns!=m.columns || !m.isValid() || !isValid()){
        rows=0; columns=0; matrix=nullptr; 
        return *this;
    }else{
        for (int i = 0; i<rows; ++i){
            for (int j=0; j<columns; ++j){
                matrix[i][j] += m.get(i+1,j+1);
            }
        }
    }
    return *this;
}

Matrix& Matrix::operator+(const Matrix& m){
    if (rows!=m.rows || columns!=m.columns || !m.isValid() || !isValid()){
        rows=0; columns=0; matrix=nullptr; 
        return *this;
    }else{
        for (int i = 0; i<rows; ++i){
            for (int j=0; j<columns; ++j){
                set(i+1, j+1, matrix[i][j] + m.get(i+1,j+1));
            }
        }
    }
    return *this;
} 