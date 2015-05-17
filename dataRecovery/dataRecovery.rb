def recover(words, clue)
  if words.count - 1 != clue.count
    return ""
  end
  size = words.count
  sentence = Array.new(size)
  # Use the sum of first N=size integers to figure out the final remaining index
  lastIndex = size * (size + 1) / 2
  clue.each_index { |i|
    place = clue[i].to_i
    word = words[i]
    sentence[place - 1] = word
    lastIndex -= place
  }
  sentence[lastIndex - 1] = words.last
  return sentence.join(" ")
end

filename = ARGV[0]
file = File.open(filename, "r")
while !file.eof?
  line = file.readline
  if line.count(";") != 0
    parts = line.split(";")
    puts recover(parts[0].split(" "), parts[1].split(" "))
  end
end
file.close
