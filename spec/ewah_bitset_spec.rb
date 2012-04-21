require 'lib/ewahbitset'

describe "An EwahBitset" do
  it "should initialize and set bits" do
    bitset = EwahBitset.new
    
    0.upto(10000000) do |i|
      bitset.set(i)
    end
    
    bitset.each do |bit|
      # puts bit
    end
    
    puts bitset.size_in_bytes
  end
end
