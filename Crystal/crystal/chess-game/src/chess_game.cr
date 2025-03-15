module Chess
  RANKS = 1..8
  FILES = 'A'..'H'

  def self.valid_square?(rank, file)
    RANKS.includes?(rank) && FILES.includes?(file) ? true : false
  end

  def self.nickname(first_name, last_name)
    first_name.upcase[0..1] + last_name.upcase[-2..-1]
  end

  def self.move_message(first_name, last_name, square)
    valid_square?(square[1].to_i, square[0]) ? "#{nickname(first_name, last_name)} moved to #{square}" : "#{nickname(first_name, last_name)} attempted to move to #{square}, but that is not a valid square"
  end
end