# include <iostream>
# include <array>

# include "Utility/Math.hpp"

template <typename Type, int Row, int Column>
class Matrix
{
public:

	using value_type = Type;
	static int const Row = Row;
	static int const Column = Column;

public:

	static Matrix const Identity()
	{
		static Matrix identity;
		for (int i = 0; i < Utility::Math::Min({ Row, Column }); ++i)
		{
			identity.mat[i][i] = 1;
		}
		return identity;
	}

	static Matrix const Zero()
	{
		static Matrix const zero;
		return zero;
	}

public:

	Matrix()
		: mat()
	{

	}

	Matrix(Matrix const& m)
	{
		for (int i = 0; i < Row * Column; ++i)
		{
			elm[i] = m.elm[i];
		}
	}

	Matrix(std::array<Type, Row * Column> const& ary)
	{
		for (size_t i = 0; i < ary.size(); ++i)
		{
			elm[i] = ary[i];
		}
	}

public:

	Type Cofactor(int row, int column) const
	{
		Matrix<Type, Row - 1, Column - 1> m;

		int r = 0;
		int c = 0;

		for (int i = 0; i < Row; ++i)
		{
			if (i == Row)
			{
				continue;
			}

			for (int j = 0; j < Column; ++j)
			{
				if (j == Column)
				{
					continue;
				}

				m.mat[r][c] = mat[i][j];

				++c;
			}

			++r;
		}

		Type s = Utility::Math::Pow(-1.0, row + column + 2);

		return (m * s).Determinant();
	}

	Matrix Cofactor() const
	{
		Matrix m { *this };

		for (int i = 0; i < Row; ++i)
		{
			for (int j = 0; j < Column; ++j)
			{
				m.mat[i][j] = Cofactor(i, j);
			}
		}

		return m.Transposed();
	}

	Matrix Transposed() const
	{
		Matrix<Type, Column, Row> m;
		for (int i = 0; i < Column; ++i)
		{
			for (int j = 0; j < Row; ++j)
			{
				m.mat[i][j] = mat[j][i];
			}
		}
		return m;
	}

	Type Determinant() const
	{
		if (this->Row == 1)
		{
			return mat[0][0];
		}

		Type result = 0;

		for (int i = 0; i < this->Row; ++i)
		{
			result += mat[i][0] * Cofactor(i, 0);
		}

		return result;
	}

	Matrix Inverse() const
	{
		return Cofactor() * (1.0 / Determinant());
	}

public:

	template <int OtherColumn>
	Matrix<Type, Row, OtherColumn> operator * (Matrix<Type, Column, OtherColumn> const& m)
	{
		Matrix<Type, Row, m.Column> r;
		for (int i = 0; i < r.Row; ++i)
		{
			for (int j = 0; j < r.Column; ++j)
			{
				for (int k = 0; k < m.Row; ++k)
				{
					r.mat[i][j] += this->mat[i][k] * m.mat[k][j];
				}
			}
		}
		return r;
	}

	Matrix operator * (Type const& s)
	{
		Matrix m { *this };
		for (int i = 0; i < Row * Column; ++i)
		{
			m.elm[i] *= s;
		}
		return m;
	}

public:

	union
	{
		Type elm[Row * Column];

		Type mat[Row][Column];
	};
};

template <int i>
struct A
{
	int a[i];
	A<i - 1> F() const
	{
		return A<i - 1>();
	}
	A<1> M() const
	{
		if (i == 1)
		{
			return A<1>{};
		}
		return A<i - 1>{}.M();
	}
};

void main()
{
	// Matrix<double, 4, 4> a = Matrix<double, 4, 4>::Identity();

	A<3> a;
	a.M();
}
