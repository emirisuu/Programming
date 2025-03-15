module TicketingReservation
    def tickets_available
        @tickets_available
    end

    def order_ticket?
        if tickets_available >= 100
            @tickets_available -= 1
            true
        else
            false
        end
    end

    def order_message(name : String)
        successful = "#{name}, your purchase was successful, your ticket number is ##{@tickets_available}, and the game is played at the #{@stadium} stadium."
        unsuccessful = "#{name}, your purchase was unsuccessful, there are not enough tickets available."
        order_ticket? ? successful : unsuccessful
    end
end

class TicketSystem
    include TicketingReservation

    def initialize(ticket_no : Int32, stadium : String)
        @tickets_available = ticket_no
        @stadium = stadium
    end
end