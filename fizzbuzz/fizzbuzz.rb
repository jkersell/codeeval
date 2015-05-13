FIZZ = "F"
BUZZ = "B"

def fizzbuzz(first, second, limit)
  1.upto(limit.to_i) {
    |num|
    isFizz = num % first.to_i == 0
    isBuzz = num % second.to_i == 0
    if isFizz and isBuzz
      print FIZZ + BUZZ + " "
    elsif isFizz
      print FIZZ + " "
    elsif isBuzz
      print BUZZ + " "
    else
      print num.to_s + " "
    end
  }
end

filename = ARGV[0]
file = File.open(filename, 'r')
while !file.eof?
  line = file.readline
  params = line.split(" ")
  fizzbuzz(params[0], params[1], params[2]);
  puts
end

