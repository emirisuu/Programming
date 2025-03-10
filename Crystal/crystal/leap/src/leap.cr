module Year
  def self.leap?(year : Number) : Bool
    if year.divisible_by?(4) && !year.divisible_by?(100)|| year.divisible_by?(4) && year.divisible_by?(100) && year.divisible_by?(400)
      return true
    end
    false
  end
end