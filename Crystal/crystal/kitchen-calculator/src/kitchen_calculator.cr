module KitchenCalculator
  MEASUREMENTS = {"milliliter" => 1, "cup" => 240, "fluid_ounce" => 30, "teaspoon" => 5, "tablespoon" => 15}

  def self.get_volume(volume_pair)
    volume_pair[1]
  end

  def self.to_milliliter(volume_pair) 
    {:milliliter, MEASUREMENTS[volume_pair[0].to_s] * volume_pair[1]}
  end

  def self.from_milliliter(volume_pair, unit)
    {unit, volume_pair[1] / MEASUREMENTS[unit.to_s]}
  end

  def self.convert(volume_pair, unit)
    from_milliliter(to_milliliter(volume_pair), unit)
  end
end
