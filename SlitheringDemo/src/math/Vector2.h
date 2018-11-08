#ifndef _MATH_VECTOR_H
#define _MATH_VECTOR_H

namespace app::math
{
	template<typename T>
	class Vector2
	{
	public: // Constructors/Destructor/Assignments
		Vector2() = default;
		Vector2(T const & _x, T const & _y);
		Vector2(Vector2 const &) = default;
		Vector2(Vector2 &&) = default;

		~Vector2() = default;

		Vector2 & operator=(Vector2 const &) = default;
		Vector2 & operator=(Vector2 &&) = default;

	public: // Public Static Functions

		// Plus operators
		
		static Vector2 operator+(Vector2 const & leftV, Vector2 const & rightV);
		static Vector2 operator+(Vector2 const & v, T const & t);
		static Vector2 operator+(T const & t, Vector2 const & v);

		// Minus operators

		static Vector2 operator-(Vector2 const & leftV, Vector2 const & rightV);
		static Vector2 operator-(Vector2 const & v, T const & t);
		static Vector2 operator-(T const & t, Vector2 const & v);

		// Multiplication operators

		static Vector2 operator*(Vector2 const & leftV, Vector2 const & rightV);
		static Vector2 operator*(Vector2 const & v, T const & t);
		static Vector2 operator*(T const & t, Vector2 const & v);

		// Division operators

		static Vector2 operator/(Vector2 const & leftV, Vector2 const & rightV);
		static Vector2 operator/(Vector2 const & v, T const & t);
		static Vector2 operator/(T const & t, Vector2 const & v);

		// Equality operators

		static constexpr bool operator==(Vector2 const & leftV, Vector2 const & rightV);
		static constexpr bool operator==(Vector2 const & v, T const & t);
		static constexpr bool operator==(T const & t, Vector2 const & v);

		// Inequality operators

		static constexpr bool operator!=(Vector2 const & leftV, Vector2 const rightV);
		static constexpr bool operator!=(Vector2 const & v, T const & t);
		static constexpr bool operator!=(T const & t, Vector2 const & v);



	public: // Public Member Functions
		Vector2 & operator+=(Vector2 const & v);
		Vector2 & operator+=(T const & t);

		Vector2 & operator-=(Vector2 const & v);
		Vector2 & operator-=(T const & t);

		Vector2 & operator*=(Vector2 const & v);
		Vector2 & operator*=(T const & t);

		Vector2 & operator/=(Vector2 const & v);
		Vector2 & operator/=(T const & t);

		operator sf::Vector2<T>() const { return sf::Vector2<T>(this->x, this->y); }

		T magnitudeSqr() const;
		T magnitude() const;
		Vector2<T> unit() const;
	public: // Public Static Variables
	public: // Public Member Variables
		T x, y;
	protected: // Protected Static Functions
	protected: // Protected Member Functions
	protected: // Protected Static Variables
	protected: // Protected Member Variables
	private: // Private Static Functions
	private: // Private Member Functions
	private: // Private Static Variables
	private: // Private Member Variables
	};

	typedef Vector2<double> Vector2d;
	typedef Vector2<float> Vector2f;
	typedef Vector2<int32_t> Vector2i;
	typedef Vector2<uint32_t> Vector2u;
}

#endif // !_MATH_VECTOR_H
