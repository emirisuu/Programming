class Pangram
  def self.pangram?(input : String) : Bool
    letters = Set(Char).new
    input.downcase.each_char do |c|
      case c
      when 'a'..'z' then letters << c
      end
    end
    letters.size == 26
  end
end

puts Pangram.pangram?("the quick brown fox jumps over the lazy dog")