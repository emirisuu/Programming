class TaskHandler
  def initialize(tasks : Array(String))
    @tasks = tasks
    @task_condition_logic = ->(x : Int32) : Bool {x >= 0}
  end

  def update_task_condition_logic(&block : Int32 -> Bool)
    @task_condition_logic = block
  end

  def execute(priority : Int32)
    if @task_condition_logic.call priority
      "Completed #{@tasks.delete @tasks.first}"
    else
      "Could not complete #{@tasks.first}"
    end
  end
end
