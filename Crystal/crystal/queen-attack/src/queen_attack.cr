class Queen
  def initialize(x : Int32, y : Int32)
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
    if x < 0 || x > 7 || y < 0 || y > 7
      raise ArgumentError.new("error")
    end
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

  def can_attack?(input : Queen) : Bool
    @chessboard[input.x][input.y] = 1
    
    return true if @chessboard[@x].count(1) > 1

    i = 0
    counter = 0
    while i < 8
      counter += 1 if @chessboard[i][@y] == 1
      return true if counter > 1
      i += 1
    end
    

    temp_x = @x
    temp_y = @y
    while temp_x > 0 && temp_y > 0
      temp_x -= 1
      temp_y -= 1
    end

    counter = 0
    while temp_x < 8 && temp_y < 8
      counter += 1 if @chessboard[temp_x][temp_y] == 1
      return true if counter > 1
      temp_x += 1
      temp_y += 1
    end
    

    temp_x = @x
    temp_y = @y
    while temp_x > 0 && temp_y > 0
      temp_x += 1
      temp_y -= 1
    end

    counter = 0
    while temp_x >= 0 && temp_y < 8
      counter += 1 if @chessboard[temp_x][temp_y] == 1
      return true if counter > 1
      temp_x -= 1
      temp_y += 1
    end
    
    false
  end
end

#puts Queen.new(2, 2).can_attack?(Queen.new(0, 4))