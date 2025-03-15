class WeighingMachine
  # Write your code here
  def initialize(precision : Int32, metric : Bool)
    @precision = precision
    @metric = metric
    @weight = 0.0
  end

  getter precision

  property weight

  setter metric

  # DO NOT MODIFY ANYTHING BELOW THIS LINE
  def weigh : String
    weight = @metric ? @weight : @weight * 2.20462
    weight = weight.round(@precision)
    weight.to_s
  end
end
