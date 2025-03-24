module Anagram
  def self.find(subject : String, candidates : Array(String)) : Array(String)
    subject.downcase
    candidates.each_with_index do |word, index|
      unless word.size == subject.size
        candidates.delete index
      end
    end
    dup_candidates = candidates.dup.map &.downcase
    subject_counter = 0
    subject.each_char do |char|
      subject_counter += char.to_i
    end
    dup_candidates.each_with_index do |word, index|
      word_counter = 0
      word.each_char do |char|
        word_counter += char.to_i
      end
      unless word_counter == subject_counter
        candidates.delete index
      end
    end
    candidates
  end
end
