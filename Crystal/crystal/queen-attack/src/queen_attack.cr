class Queen
  def initialize(x : Int32, y : Int32) : Bool
    @chessboard = 
    [
      [0,0,0,0,0,0,0,0],
      [0,0,0,0,0,0,0,0],
      [0,0,0,0,0,0,0,0],
      [0,0,0,0,0,0,0,0],
      [0,0,0,0,0,0,0,0],
      [0,0,0,0,0,0,0,0],
      [0,0,0,0,0,0,0,0],
      [0,0,0,0,0,0,0,0]
    ]
    raise ArgumentError if x < 0 || x > 7 || y < 0 || y > 7

    @x = x
    @y = y
    @chessboard[x][y] = 1
  end

  def x
    @x
  end

  def y
    @y
  end

  def self.can_attack?(Queen1)
    @chessboard[Queen1.x][Queen1.y] = 1
    return true if @chessboard[@x].count(1) > 1
    
  end
end
