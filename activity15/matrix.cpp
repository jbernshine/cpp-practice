#include <iostream>
#include <array>

template<typename T, int R, int C>
class Matrix {
    std::array<T, R * C> data;
    public:
        Matrix() : data({}) {};
        Matrix(std::array<T, R * C> initialValues) : data(initialValues) {};

        T& get(int row, int col) {
            if (row >= R || col >= C) {
                std::abort();
            }
            return data[row*C + col];
        }
        
        std::array<T, R> multiply(const std::array<T, C>& vector) {
            std::array<T, R> result = {};

            for (size_t r = 0; r < R; r++) {
                for (size_t c = 0; c < C; c++) {
                    result[r] += get(r, c) * vector[c];
                }
            }
            return result;
        }
};

template<typename T, int R, int C>
std::ostream& operator<<(std::ostream& os, Matrix<T, R, C>& matrix) {
    os << '\n';
        for (int r = 0; r < R; r++) {
            for( int c = 0; c < C; c++) {
                os << matrix.get(r, c) << ' ';
            }
            os << "\n";
        }
        return os;
}

int main() {
    Matrix<int, 3, 2> matrix({
        1, 2,
        3, 4,
        5, 6
    });

    std::cout << "Initial matrix:" << matrix << std::endl;
    matrix.get(1, 1) = 7;
    std::cout << "Modified matrix:" << matrix << std::endl;

    std::array<int, 2> vector = {8, 9};
    std::array<int, 3> result = matrix.multiply(vector);
    std::cout << "Result of multiplication: [" << result[0] << ", "
    << result[1] << ", " << result[2] << "]" << std::endl;

    return 0;
}
