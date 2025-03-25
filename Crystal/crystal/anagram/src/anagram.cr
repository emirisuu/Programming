module Anagram
  def self.find(subject : String, candidates : Array(String)) : Array(String)
    subject.downcase
    dup_candidates = candidates.dup.map &.downcase
    subject_array = Array(Char).new
    subject.each_char do |char|
      subject_array << char
    end
    dup_candidates.each_with_index do |word, index|
      if word.downcase == subject || word.size != subject.size
        candidates.delete_at index
        dup_candidates.delete_at index
      else
        word_array = Array(Char).new
        word.each_char do |char|
          word_array << char
        end
        unless word_array.sort == subject_array.sort
          candidates.delete_at index
          dup_candidates.delete_at index
        end
      end
    end
    candidates
  end
end
