module Bob
  def self.hey(string : String) : String
    string = string.strip.gsub("\t", "")
    temp = string.upcase
    case string
    when string.empty? || string.blank? then "Fine. Be that way!"
    when string[-1] == '?' then string == temp ? "Calm down, I know what I'm doing!" : "Sure."
    else string == temp ? "Whoa, chill out!" : "Whatever."
    end
  end
end
