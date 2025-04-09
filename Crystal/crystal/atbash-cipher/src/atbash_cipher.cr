module AtbashCipher
  ALPHABET = "abcdefghijklmnopqrstuvwxyz"
  CIPHER = ALPHABET.reverse
  # Write your code for the 'Atbash Cipher' exercise in this file.
  def self.encode(message : String) : String
    message = message.downcase
    message = message.gsub(" ", "")
    encoded_message = ""
    temp_message = ""
    message.each_char_with_index do |char, index|
      if char.letter?
        temp_message += CIPHER[ALPHABET.index! char]
      elsif char.number?
        temp_message += char
      end
      if temp_message.size == 5
        encoded_message += temp_message + " "
        temp_message = ""
      elsif index == message.size - 1
        encoded_message += temp_message
      end
    end
    encoded_message.strip
  end

  def self.decode(message : String) : String
    message = message.gsub " ", ""
    decoded_message = ""
    message.each_char do |char|
      if char.letter?
        decoded_message += ALPHABET[CIPHER.index! char]
      else
        decoded_message += char
      end
    end
    decoded_message
  end
end
