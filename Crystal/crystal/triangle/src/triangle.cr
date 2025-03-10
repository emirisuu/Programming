class Triangle
    @a : Float64
    @b : Float64
    @c : Float64

    def initialize(triangle_array : Tuple(Float64, Float64, Float64))
        @a, @b, @c = triangle_array
        
        if 0.0 == @a * @b * @c
            raise ArgumentError.new "Not a triangle"
        end
        unless 2 * triangle_array.max < triangle_array.sum
            raise ArgumentError.new "Triangle inequality violation"
        end
    end

    def initialize(triangle_array : Tuple(Int32, Int32, Int32))
        initialize triangle_array.map(&.to_f)
    end

    def equilateral? : Bool
        @a == @b == @c
    end

    def isosceles? : Bool
        @a == @b || @a == @c || @b == @c
    end

    def scalene? : Bool
        !isosceles?
    end

end