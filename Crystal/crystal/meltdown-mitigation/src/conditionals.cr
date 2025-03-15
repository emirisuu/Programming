class Reactor
  def self.criticality_balanced?(temperature, neutrons_emitted)
    temperature < 800 && neutrons_emitted > 500 && (temperature * neutrons_emitted) < 500000 ? true : false
  end

  def self.reactor_efficiency(voltage, current, theoretical_max_power)
    generated_power = voltage * current
    percentage = (generated_power / theoretical_max_power) * 100
    if percentage >= 80
      "green"
    elsif percentage >= 60
      "orange"
    elsif percentage >= 30
      "red"
    else
      "black"
    end
  end

  def self.fail_safe(temperature, neutrons_produced_per_second, threshold)
    percentage = temperature * neutrons_produced_per_second
    if percentage < threshold * 0.9
      "LOW"
    elsif threshold * 1.1 > percentage > threshold * 0.9
      "NORMAL"
    else
      "DANGER"
    end
  end
end
