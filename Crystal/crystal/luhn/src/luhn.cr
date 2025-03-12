module Luhn
  def self.valid?(input : String) : Bool
    input = input.chars.reject &.whitespace?
    return false if input.size <= 1
    sum = 0
    input.reverse.each_with_index do |number, i|
      temp = number.to_i?
      return false if temp.nil?
      temp = temp * (1 + i % 2)
      temp -= 9 if temp > 9
      sum += temp
    end
    (sum % 10).zero?
  end
end

puts Luhn.valid?(" 0")