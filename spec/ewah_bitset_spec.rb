require 'lib/ewahbitset'

describe "An EwahBitset" do
  it "should initialize and set bits" do
    bitset = EwahBitset.new
    
    0.upto(10) do |i|
      bitset.set(i * 10)
    end
    
    bitset.each do |bit|
      puts bit
    end
    
    puts bitset.size_in_bytes
    serialized = bitset.serialize
    
    newBitset = EwahBitset.new.deserialize(serialized)
    
    newBitset.each do |bit|
      puts bit
    end
  end
end
