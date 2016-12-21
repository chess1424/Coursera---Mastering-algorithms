s     = gets.chomp
stack = []

def status_of_char(char)
  if(char == '[' || char == '{' || char == '(')
   "open"
  elsif(char == ']' || char == '}' || char == ')')
   "close"
  else
   "none"
  end
end

def is_valid_operation?(open, close)
  open == '(' && close == ')' || open == '{' && close == '}' || open == '[' && close == ']'
end

valid = true
for i in 0...s.length
  char   = s[i];
  status = status_of_char(char)

  next if status == "none"

  if status == "open"
    stack << [char, i]
  else
    if stack.empty? || !is_valid_operation?(stack.pop.first, char)
      valid = false
      break
    end
  end
end

if stack.empty? && valid
  puts "Success"
else
  if !valid
    puts i + 1
  else
    puts stack.pop.last + 1
  end
end
