#include <iostream>
#include <array>
#include <functional>

template<int R, int C, typename T = int, typename Multiply=std::multiplies<T> >
class Matrix {
    std::array<T, R * C> data;
    Multiply multiplier;
    public:
        Matrix() : data({}), multiplier() {};
        Matrix(std::array<T, R * C> initialValues) : data(initialValues), multiplier() {};

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
                    result[r] += multiplier(get(r, c), vector[c]);
                }
            }
            return result;
        }
};

template<int R, int C, typename T, typename Mult>
std::ostream& operator<<(std::ostream& os, Matrix<R, C, T, Mult>& matrix) {
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
    Matrix<3, 2, int, std::plus<int>> matrixAdd({
        1, 2,
        3, 4,
        5, 6
    });

    std::array<int, 2> vector = {8, 9};
    std::array<int, 3> result = matrixAdd.multiply(vector);
    std::cout << "Result of multiplication(with +): [" << result[0] << ", "
    << result[1] << ", " << result[2] << "]" << std::endl;

    return 0;
}
