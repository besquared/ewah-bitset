require 'lib/ewahbitset'

describe "An EwahBitset" do
  it "should initialize and set bits" do
    bitset = EwahBitset.new
    
    0.upto(100) do |i|
      bitset.set(i * 10)
    end
    
    bitset.each do |bit|
      puts bit
    end
    
    puts bitset.size_in_bytes
    bytes = bitset.to_bytes
    
    puts bytes.inspect
    
    newBitset = EwahBitset.new
    newBitset.from_bytes(bytes)
    
    puts "PUTTING DESERIALIZED"
    newBitset.each do |bit|
      puts bit
    end
  end
end
