class CastleDinner
  def self.check_food?(food)
    unless food == "Mushroom pasties"
      return nil
    end
    food
  end

  def self.check_drink?(drink)
    return nil unless drink.downcase.includes?("i")
    drink
  end

  def self.replace_drink(drink)
    return "Apple juice" if check_drink?(drink).nil?
    drink
  end
end