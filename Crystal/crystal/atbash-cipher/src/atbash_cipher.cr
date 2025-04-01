module AtbashCipher
  # Write your code for the 'Atbash Cipher' exercise in this file.
  def self.encode(message : String) : String
    message = message.downcased 
    message = message.gsub(" ", "")
    alphabet = "abcdefghijklmnopqrstuvwxyz"
    cipher = alphabet.reversed
    
  end

  def self.decode(message : String) : String
  end
end
