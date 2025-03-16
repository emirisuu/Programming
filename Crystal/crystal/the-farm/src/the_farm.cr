class InvalidCowsError < Exception
  def initialize(@number_of_cows : Int32, message : String)
    @message = "#{@number_of_cows} cows are invalid: #{message}"
  end
end


module TheFarm
  def self.divide_food(food : FodderCalculator, number_of_cows : Int32)
    begin
      total_amount = food.fodder_amount!
      multiplier = food.fattening_factor!
      total_amount * multiplier / number_of_cows
    rescue
      0
    end
  end

  def self.validate_input_and_divide_food(food : FodderCalculator, number_of_cows : Int32)
    number_of_cows > 0 ? divide_food food, number_of_cows : raise "Number of cows must be greater than 0"
  end

  def self.validate_number_of_cows(number_of_cows : Int32)
    case number_of_cows
    when 0 then raise InvalidCowsError.new(number_of_cows, "no cows don't need food")
    else number_of_cows < 0 ? raise InvalidCowsError.new(number_of_cows, "there are no negative cows") : nil
    end
  end
end