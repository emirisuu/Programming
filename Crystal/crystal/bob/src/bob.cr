module Bob
  def self.hey(string : String) : String
    string = string.strip.gsub("\t", "")
    case string
    when string.empty? || string.blank? then "Fine. Be that way!"
    when string[-1] == '?' then string == string.upcase ? "Calm down, I know what I'm doing!" : "Sure."
    when string.empty? || string.blank? then "Fine. Be that way!"
    else string == string.upcase ? "Whoa, chill out!" : "Whatever."
    end
  end
end
