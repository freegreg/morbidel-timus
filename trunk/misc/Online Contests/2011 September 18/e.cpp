#include <cstdlib>
#include <cstdio>
#include <math.h>

using namespace std;


/* 
 * a simple exception class
 * you can create an exeption by entering
 *      throw Exception("...Error description...");
 * and get the error message from the data msg for displaying:
 *      err.msg
 */
class Exception {
   public:
        char* msg;
      Exception(  char* arg) : msg(arg) { };
};
class complex
{
     private:
                  double real;               // Real Part
            double imag;      //  Imaginary Part
 
 
   public:
          complex(double,double);
          complex(complex&);
          complex operator +(complex);
          complex operator -(complex);
          complex operator *(complex);
          complex operator /(complex);
          complex getconjugate();
          complex getreciprocal();
          double getmodulus();
          bool operator ==(complex);
          void operator =(complex);
};
//                                         RUCTOR
complex::complex(double r=0.0f,double im=0.0f)
{
real=r;
imag=im;
}

//                                 COPY  RUCTOR
complex::complex(complex &c)
{
this->real=c.real;
this->imag=c.imag;
}


void complex::operator =(complex c)
{
real=c.real;
imag=c.imag;
}


complex complex::operator +(complex c)
{
complex tmp;
tmp.real=this->real+c.real;
tmp.imag=this->imag+c.imag;
return tmp;
}

complex complex::operator -(complex c)
{
complex tmp;
tmp.real=this->real - c.real;
tmp.imag=this->imag - c.imag;
return tmp;
}

complex complex::operator *(complex c)
{
complex tmp;
tmp.real=(real*c.real)-(imag*c.imag);
tmp.imag=(real*c.imag)+(imag*c.real);
return tmp;
}

complex complex::operator /(complex c)
{
double div=(c.real*c.real) + (c.imag*c.imag);
complex tmp;
tmp.real=(real*c.real)+(imag*c.imag);
tmp.real/=div;
tmp.imag=(imag*c.real)-(real*c.imag);
tmp.imag/=div;
return tmp;
}

complex complex::getconjugate()
{
complex tmp;
tmp.real=this->real;
tmp.imag=this->imag * -1;
return tmp;
}

complex complex::getreciprocal()
{
complex t;
t.real=real;
t.imag=imag * -1;
double div;
div=(real*real)+(imag*imag);
t.real/=div;
t.imag/=div;
return t;
}

double complex::getmodulus()
{
double z;
z=(real*real)+(imag*imag);
z=sqrt(z);
return z;
}

bool complex::operator ==(complex c)
{
return (real==c.real)&&(imag==c.imag) ? 1 : 0;
}

class Matrix
{
public:
    //  ructors
    Matrix()
    {
        //printf("Executing  ructor Matrix() ...\n");
        // create a Matrix object without content
        p = NULL;
        rows = 0;
        cols = 0;
    }
    Matrix(  int row_count,   int column_count)
    {
        // create a Matrix object with given number of rows and columns
        //printf("Executing  ructor Matrix(  int column_count,   int row_count) ...\n");
        p = NULL;

        if (row_count > 0 && column_count > 0)
        {
            rows = row_count;
            cols = column_count;

            p = new complex*[rows];
            for (int r = 0; r < rows; r++)
            {
                p[r] = new complex[rows];

                // initially fill in zeros for all values in the matrix;
                for (int c = 0; c < cols; c++)
                {
                    p[r][c] = 0;
                }
            }
        }
    }
    // assignment operator
    Matrix(  Matrix& a)
    {
        //printf("Executing  ructor Matrix(  Matrix& a) ...\n");
        rows = a.rows;
        cols = a.cols;
        p = new complex*[a.rows];
        for (int r = 0; r < a.rows; r++)
        {
            p[r] = new complex[a.cols];

            // copy the values from the matrix a
            for (int c = 0; c < a.cols; c++)
            {
                p[r][c] = a.p[r][c];
            }
        }
    }

    // index operator. You can use this class like myMatrix(col, row)
    // the indexes are one-based, not zero based.
	complex& operator()(  int r,   int c)
	{
        //printf("Executing Matrix operator() ...\n");
      	if (p != NULL && r > 0 && r <= rows && c > 0 && c <= cols)
      	{
          	return p[r-1][c-1];
        }
      	else
      	{
            throw Exception("Subscript out of range");
        }
    }

    // assignment operator
    Matrix& operator= (  Matrix& a)
    {
        //printf("Executing Matrix operator= ...\n");
        rows = a.rows;
        cols = a.cols;
        p = new complex*[a.rows];
        for (int r = 0; r < a.rows; r++)
        {
            p[r] = new complex[a.cols];

            // copy the values from the matrix a
            for (int c = 0; c < a.cols; c++)
            {
                p[r][c] = a.p[r][c];
            }
        }
        return *this;
    }

    // operator addition
    friend Matrix operator+(  Matrix& a,   Matrix& b)
    {
        // check if the dimensions match
        if (a.rows == b.rows && a.cols == b.cols)
        {
         	Matrix res(a.rows, a.cols);

            for (int r = 0; r < a.rows; r++)
            {
                for (int c = 0; c < a.cols; c++)
                {
                    res.p[r][c] = a.p[r][c] + b.p[r][c];
                }
            }
         	return res;
        }
        else
        {
            // give an error
            throw Exception("Dimensions does not match");
        }

        // return an empty matrix (this never happens but just for safety)
        return Matrix();
    }

    // add a complex value (elements wise)
    Matrix& add(complex v)
    {
        for (int r = 0; r < rows; r++)
        {
            for (int c = 0; c < cols; c++)
            {
                p[r][c] += v;
            }
        }
     	return *this;
    }

    // subtract a complex value (elements wise)
    Matrix& subtract(complex v)
    {
        return add(-v);
    }

    // multiply a complex value (elements wise)
    Matrix& multiply(complex v)
    {
        for (int r = 0; r < rows; r++)
        {
            for (int c = 0; c < cols; c++)
            {
                p[r][c] *= v;
            }
        }
     	return *this;
    }

    // operator subtraction
    friend Matrix operator- (  Matrix& a,   Matrix& b)
    {
        // check if the dimensions match
        if (a.rows == b.rows && a.cols == b.cols)
        {
         	Matrix res(a.rows, a.cols);

            for (int r = 0; r < a.rows; r++)
            {
                for (int c = 0; c < a.cols; c++)
                {
                    res.p[r][c] = a.p[r][c] - b.p[r][c];
                }
            }
         	return res;
        }
        else
        {
            // give an error
            throw Exception("Dimensions does not match");
        }

        // return an empty matrix (this never happens but just for safety)
        return Matrix();
    }
    // operator unary minus
    friend Matrix operator- (  Matrix& a)
    {
     	Matrix res(a.rows, a.cols);

        for (int r = 0; r < a.rows; r++)
        {
            for (int c = 0; c < a.cols; c++)
            {
                res.p[r][c] = -a.p[r][c];
            }
        }
    
        return res;
    }
    
    // operator multiplication
    friend Matrix operator* (  Matrix& a,   Matrix& b)
    {
        // check if the dimensions match
        if (a.cols == b.rows)
        {
         	Matrix res(a.rows, b.cols);

            for (int r = 0; r < a.rows; r++)
            {
                for (int c_res = 0; c_res < b.cols; c_res++)
                {
                    for (int c = 0; c < a.cols; c++)
                    {
                        res.p[r][c_res] += a.p[r][c] * b.p[c][c_res];
                    }
                }
            }
         	return res;
        }
        else
        {
            // give an error
            throw Exception("Dimensions does not match");
        }

        // return an empty matrix (this never happens but just for safety)
        return Matrix();
    }

    /**
     * returns the minor from the given matrix where
     * the selected row and column are removed
     */
    Matrix minor(  int row,   int col)
    {
        //printf("minor(row=%i, col=%i), rows=%i, cols=%i\n", row, col, rows, cols);
        Matrix res;
      	if (row > 0 && row <= rows && col > 0 && col <= cols)
      	{
            res = Matrix(rows - 1, cols - 1);
            
            // copy the content of the matrix to the minor, except the selected
            for (int r = 1; r <= (rows - (row >= rows)); r++)
            {
                for (int c = 1; c <= (cols - (col >= cols)); c++)
                {
                    //printf("r=%i, c=%i, value=%f, rr=%i, cc=%i \n", r, c, p[r-1][c-1], r - (r > row), c - (c > col));
                    res(r - (r > row), c - (c > col)) = p[r-1][c-1];
                }
            }        
        }
        else
        {
            throw Exception("Index for minor out of range");
        }
        
        return res;
    }
    
    /* 
     * returns the size of the i-th dimension of the matrix.
     * i.e. for i=1 the function returns the number of rows, 
     * and for i=2 the function returns the number of columns
     * else the function returns 0
     */
    int size(  int i)
    {
        if (i == 1)
        {
            return rows;
        }
        else if (i == 2)
        {
            return cols;
        }
        return 0;
    }

    // returns the number of rows
    int get_rows()
    {
        return rows;
    }
    
    // returns the number of columns
    int get_cols()
    {
        return cols;
    }

    // print the contents of the matrix
    void print()
    {
        if (p != NULL)
        {
            printf("[");
            for (int r = 0; r < rows; r++)
            {
                if (r > 0)
                {
                    printf(" ");
                }
                for (int c = 0; c < cols-1; c++)
                {
                    printf("%.2f, ", p[r][c]);
                }
                if (r < rows-1)
                {
                    printf("%.2f;\n", p[r][cols-1]);
                }
                else
                {
                    printf("%.2f]\n", p[r][cols-1]);
                }
            }
        }
        else
        {
            // matrix is empty
            printf("[ ]\n");
        }
    }

public:
    // destructor
    ~Matrix()
    {
        // clean up allocated memory
        for (int r = 0; r < rows; r++)
        {
            delete p[r];
        }
        delete p;
        p = NULL;
    }

private:
    int rows;
    int cols;
    complex** p;         // pointer to a matrix with complex
};

/* 
 * i.e. for i=1 the function returns the number of rows,
 * and for i=2 the function returns the number of columns
 * else the function returns 0
 */
int size(Matrix& a,   int i)
{
    return a.size(i);
}


// addition of Matrix with complex
Matrix operator+ (  Matrix& a,   complex B)
{
    Matrix res = a;
    res.add(B);
    return res;
}
// addition of complex with Matrix
Matrix operator+ (  complex b,   Matrix& a)
{
    Matrix res = a;
    res.add(b);
    return res;
}

// subtraction of Matrix with complex
Matrix operator- (  Matrix& a,   complex b)
{
    Matrix res = a;
    res.subtract(b);
    return res;
}
// subtraction of complex with Matrix
Matrix operator- (  complex b,   Matrix& a)
{
    Matrix res = -a;
    res.add(b);
    return res;
}

// multiplication of Matrix with complex
Matrix operator* (  Matrix& a,   complex b)
{
    Matrix res = a;
    res.multiply(b);
    return res;
}
// multiplication of complex with Matrix
Matrix operator* (  complex b,   Matrix& a)
{
    Matrix res = a;
    res.multiply(b);
    return res;
}


/**
 * returns a matrix with size cols x rows with ones as values
 */
Matrix ones(  int rows,   int cols)
{
    Matrix res = Matrix(rows, cols);

    for (int r = 1; r <= rows; r++)
    {
        for (int c = 1; c <= cols; c++)
        {
            res(r, c) = 1;
        }
    }
    return res;
}

/**
 * returns a matrix with size cols x rows with zeros as values
 */
Matrix zeros(  int rows,   int cols)
{
    return Matrix(rows, cols);
}


/**
 * returns a diagonal matrix with size n x n with ones at the diagonal
 * @param   v a vector
 * @return  a diagonal matrix with ones on the diagonal
 */
Matrix diag(  int n)
{
    Matrix res = Matrix(n, n);
    for (int i = 1; i <= n; i++)
    {
        res(i, i) = 1;
    }
    return res;
}
/**
 * returns a diagonal matrix
 * @param   v a vector
 * @return  a diagonal matrix with the given vector v on the diagonal
 */
Matrix diag(Matrix& v)
{
    Matrix res;
    if (v.get_cols() == 1)
    {
        // the given matrix is a vector n x 1
        int rows = v.get_rows();
        res = Matrix(rows, rows);
        
        // copy the values of the vector to the matrix
        for (int r=1; r <= rows; r++)
        {
            res(r, r) = v(r, 1);
        }
    }
    else if (v.get_rows() == 1)
    {
        // the given matrix is a vector 1 x n
        int cols = v.get_cols();
        res = Matrix(cols, cols);

        // copy the values of the vector to the matrix
        for (int c=1; c <= cols; c++)
        {
            res(c, c) = v(1, c);
        }        
    }
    else
    {
        throw Exception("Parameter for diag must be a vector");
    }
    return res;
}

/*
 * returns the determinant of Matrix a
 */
complex det(Matrix& a)
{
    complex d = 0;       // value of the determinant
    int rows = a.get_rows();
    int cols = a.get_cols();
    
    if (rows == cols)
    {
        // this is a square matrix
        if (rows == 1)
        {
            // this is a 1 x 1 matrix
            d = a(1, 1);
        }
        else if (rows == 2)
        {
            // this is a 2 x 2 matrix
            // the determinant of [a11,a12;a21,a22] is det = a11*a22-a21*a12
            d = a(1, 1) * a(2, 2) - a(2, 1) * a(1, 2);
        }
        else
        {
            // this is a matrix of 3 x 3 or larger
            for (int c = 1; c <= cols; c++)
            {
                Matrix M = a.minor(1, c);
                //d += pow(-1, 1+c)  * a(1, c) * det(M);
                d += (c%2 + c%2 - 1) * a(1, c) * det(M);  // faster than with pow()
            }
        }
    }
    else
    {
        throw Exception("Matrix must be square");
    }
    return d;
}

// swap two values
void swap(complex& a, complex& b)
{
    complex temp = a;
    a = b;
    b = temp;
}

/*
 * returns the inverse of Matrix a
 */
Matrix inv(Matrix& a)
{
    Matrix res;
    complex d = 0;       // value of the determinant
    int rows = a.get_rows();
    int cols = a.get_cols();
    
    d = det(a);
    if (rows == cols && d != 0)
    {
        // this is a square matrix
        if (rows == 1)
        {
            // this is a 1 x 1 matrix
            res = Matrix(rows, cols);
            res(1, 1) = 1 / a(1, 1);
        }
        else if (rows == 2)
        {
            // this is a 2 x 2 matrix
            res = Matrix(rows, cols);
            res(1, 1) = a(2, 2);
            res(1, 2) = -a(1, 2);
            res(2, 1) = -a(2, 1);
            res(2, 2) = a(1, 1);
            res = (1/d) * res;
        }
        else
        {
            // this is a matrix of 3 x 3 or larger
            // calculate inverse using gauss-jordan elimination
            //      [url="http://mathworld.wolfram.com/MatrixInverse.html"]http://mathworld.wolfram.com/MatrixInverse.html[/url]
            //      [url="http://math.uww.edu/~mcfarlat/inverse.htm"]http://math.uww.edu/~mcfarlat/inverse.htm[/url]
            res = diag(rows);     // a diagonal matrix with ones at the diagonal
            Matrix ai = a;        // make a copy of Matrix a

            for (int c = 1; c <= cols; c++)
            {
                // element (c, c) should be non zero. if not, swap content 
                // of lower rows
                int r;
                for (r = c; r <= rows && ai(r, c) == 0; r++)
                {
                }                
                if (r != c)
                {
                    // swap rows
                    for (int s = 1; s <= cols; s++)
                    {
                        swap(ai(c, s), ai(r, s));
                        swap(res(c, s), res(r, s));
                    }
                }

                // eliminate non-zero values on the other rows at column c
                for (int r = 1; r <= rows; r++)
                {
                    if(r != c)
                    {
                        // eleminate value at column c and row r
                        if (ai(r, c) != 0)
                        {
                            complex f = - ai(r, c) / ai(c, c);
                            
                            // add (f * row c) to row r to eleminate the value
                            // at column c
                            for (int s = 1; s <= cols; s++)
                            {
                                ai(r, s) += f * ai(c, s);
                                res(r, s) += f * res(c, s);
                            }
                        }                    
                    }
                    else
                    {
                        // make value at (c, c) one,
                        // divide each value on row r with the value at ai(c,c)
                        complex f = ai(c, c);
                        for (int s = 1; s <= cols; s++)
                        {
                            ai(r, s) /= f;
                            res(r, s) /= f;
                        }                        
                    }
                }                
            }
        }
    }
    else
    {
        if (rows == cols)
        {
            throw Exception("Matrix must be square");
        }
        else
        {
            throw Exception("Determinant of matrix is zero");
        }
    }
    return res;
}


int main(int argc, char *argv[])
{
    // create an empty matrix of 3x3 (will initially contain zeros)
    int cols = 3;
    int rows = 3;
    Matrix A = Matrix(cols, rows);

    // fill in some values in matrix a
    int count = 0;
    for (int r = 1; r <= rows; r++)
    {
        for (int c = 1; c <= cols; c++)
        {
            count ++;
            A(r, c) = count;
        }
    }

    return EXIT_SUCCESS;
}
