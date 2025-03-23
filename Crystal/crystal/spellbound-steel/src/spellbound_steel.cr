module SpellboundSteel
  def self.find_card?(cards, card)
    cards.index card
  end

  def self.capitalize_names(characters)
    new = characters.map do |card_name|
      if card_name.includes? " "
        card_name.sub(card_name[0], card_name[0].upcase)
        index = card_name.index(" ")
        card_name.sub(card_name[index + 1], card_name[index + 1].upcase)
      else
        card_name.capitalize
      end
    end
    new
  end

  def self.calculate_power_level(cards)
    sum = 0
    cards.each do |card|
      case card
      when "Warrior" then sum += 10
      when "Mage" then sum += 20
      when "Rogue" then sum += 30
      when "Fireball" then sum += 15
      when "Ice Storm" then sum += 25
      when "Lightning Bolt" then sum += 35
      end
    end
    sum
  end

  def self.decode_characters(character)
    character.each_char_with_index do |char, index|
      unless index.odd?
        character.sub(char, "")
      end
    end
    character
  end
end
