module SpellboundSteel
  def self.find_card?(cards, card)
    cards.index card
  end

  def self.capitalize_names(characters)
    characters.map &.titleize
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
    new = ""
    character.each_char_with_index do |char, index|
      unless index.odd?
        new += char
      end
    end
    new
  end
end
