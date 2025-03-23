module ColossalCoaster
  def self.add_to_queue(express_queue, normal_queue, express, person_name)
    case express
    when 0 then normal_queue << person_name
    when 1 then express_queue << person_name
    end
  end

  def self.find_my_friend(queue, friend_name)
    queue.index friend_name
  end

  def self.add_with_friends(queue, friend_name, person_name)
    index = find_my_friend(queue, friend_name)
    unless index.nil?
      queue.insert(index, person_name)
    else 
      queue
    end
  end

  def self.remove_from_queue(queue, person_name)
    queue.delete person_name
    queue
  end

  def self.sorted_queue(queue)
    queue.sort
  end
end
