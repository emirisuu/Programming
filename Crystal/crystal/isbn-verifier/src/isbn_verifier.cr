module IsbnVerifier
  def self.valid?(isbn : String) : Bool
    if !((isbn.size == 13) || (isbn.size == 10))
      return false
    end
    temp_counter = 0
    counter = 0
    sum = 0
    while counter < isbn.size
      if counter == isbn.size - 1
        if isbn[counter] == 'X'
          sum += 10
        elsif isbn[counter].number?
          sum += isbn[counter].to_i
        else
          return false
        end
      elsif isbn[counter].number?
        sum += isbn[counter].to_i * (10 - temp_counter)
        temp_counter += 1
      end
      counter += 1
    end
    sum % 11 == 0
  end
end

puts IsbnVerifier.valid?("359821507X")