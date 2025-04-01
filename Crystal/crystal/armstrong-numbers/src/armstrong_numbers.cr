module ArmstrongNumbers
  def self.armstrong_number?(input : Number) : Bool
    sum = 0
    input.to_s.each_char do |char|
      sum += char.to_i ** input.to_s.size
    end
    sum == input
  end
end
