module Anagram
  def self.find(subject : String, candidates : Array(String)) : Array(String)
    subject = subject.downcase
    subject_array = Array(Char).new
    subject.each_char do |char|
      subject_array << char
    end
    index = 0
    while index < candidates.size
      if candidates[index].size != subject.size || candidates[index].downcase == subject
        candidates.delete_at index
        index -= 1
      else
        temp = candidates[index].downcase
        temp_array = Array(Char).new
        temp.each_char do |char|
          temp_array << char
        end
        unless temp_array.sort == subject_array.sort
          candidates.delete_at index
          index -= 1
        end
      end
      index += 1
    end
    candidates
  end
end
