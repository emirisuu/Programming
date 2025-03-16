class PasswordLock
    @password : (Float64 | Int32 | String)

    def initialize(password : (Float64 | Int32 | String))
        @password = password
    end

    def encrypt
        temp = @password
        if temp.is_a?(Int32)
            temp = (temp / 2).round
            @password = temp
        elsif temp.is_a?(String)
            temp = temp.reverse
            @password = temp
        else
            @password *= 4
        end
    end

    def unlock?(password_attempt)
        if password_attempt.is_a?(Int32)
            (password_attempt / 2).round == @password ? "Unlocked" : nil
        elsif password_attempt.is_a?(String)
            password_attempt.reverse == @password ? "Unlocked" : nil
        else
            password_attempt * 4 == @password ? "Unlocked" : nil
        end    
    end
end

password_lock = PasswordLock.new(1234)
password_lock.encrypt
puts password_lock.unlock?(1234)