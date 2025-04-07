module AtbashCipher
  # Write your code for the 'Atbash Cipher' exercise in this file.
  def self.encode(message : String) : String
    message = message.downcase
    message = message.gsub(" ", "")
    alphabet = "abcdefghijklmnopqrstuvwxyz"
    cipher = alphabet.reverse
    encoded_message = ""
    temp_message = ""
    message.each_char_with_index do |char, index|
      if char.letter?
        temp_message += cipher[alphabet.index char]
      elsif char.number?
        temp_message += char
      end
      if temp_message.size == 5
        encoded_message += temp_message + " "
        temp_message = ""
      end
    end
    encoded_message
  end

  def self.decode(message : String) : String
  end
end
