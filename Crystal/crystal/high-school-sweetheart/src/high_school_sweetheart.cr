class HighSchoolSweetheart
  def self.clean_up_name(name)
    name = name.chomp.gsub("-", " ").strip
    name
  end

  def self.first_letter(name)
    name = clean_up_name name
    name[0]
  end

  def self.initial(name)
    name = first_letter name
    name.upcase + "."
  end

  def self.pair(name1, name2)
    name1 = initial name1
    name2 = initial name2
    name1 = name1.insert(0, "❤")
    name1 = name1.insert(1, " ")
    name2 = name2.insert(2, "❤")
    name2 = name2.insert(2, " ")
    "#{name1}  +  #{name2}"
  end
end
