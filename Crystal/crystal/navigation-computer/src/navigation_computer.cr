class Navigation
  NEPTUNE_DISTANCE = 4400000000_i64
  MARS_DISTANCE = 227940000_i32
  ATMOSPHERE_DISTANCE = 10000_i16

  def correct_area_analysis(measurement)
    measurement.to_u
  end

  def calculate_velocity(distance, time)
    (distance / time).to_f32
  end
end
