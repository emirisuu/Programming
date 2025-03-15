class Library
  def self.first_letter(title : String) : Char
    title[0]
  end

  def self.initials(first_name : String, last_name : String) : String
    "#{first_name[0]}.#{last_name[0]}"
  end

  def self.decrypt_character(character : Char) : Char
    return 'Z' if character == 'A'
    return 'z' if character == 'a' 
    character.pred
  end

  def self.decrypt_text(text : String) : String
    new_text = ""
    text.each_char do |chr|
      chr.letter? ? (new_text += decrypt_character chr) : (new_text += chr)
    end
    new_text
  end
end