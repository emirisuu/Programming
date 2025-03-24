module Acronym
  def self.abbreviate(phrase : String) : String
    phrase = phrase.gsub("-", " ")
    phrase.each_char do |char|
      unless char.ascii_letter? || char.ascii_whitespace?
        phrase = phrase.gsub(char, "")
      end
    end
    acronym = ""
    phrase.split.each do |word|
      acronym += word[0].upcase
    end
    acronym
  end
end
