require 'lib/ewahbitset'

describe "An EwahBitset" do
  before(:each) do
    @bitset = EwahBitset.new
  end
  
  it "should set bits" do
    positions = []
    0.upto(10) do |i|
      @bitset.set(i * 10)
      positions << i * 10
    end
    
    bPositions = []
    @bitset.each do |pos|
      bPositions << pos
    end
    
    positions.should == bPositions
    @bitset.size_in_bits.should == 101
  end
  
  it "should reset" do
    0.upto(10) do |i|
      @bitset.set(i * 10)
    end
    
    @bitset.size_in_bits.should == 101
    @bitset.reset
    @bitset.size_in_bits.should == 0
  end
  
  it "should compare" do
    other = EwahBitset.new
    
    0.upto(10) do |i|
      @bitset.set(i * 10)
      other.set(i * 10)
    end
    
    @bitset.should == other
  end
  
  it "should perform a logical or" do
    other = EwahBitset.new
    
    positions = []
    0.upto(5) do |i|
      @bitset.set(i * 10)
      positions << i * 10
    end
    
    6.upto(10) do |i|
      other.set(i * 10)
      positions << i * 10
    end
    
    newbits = @bitset.logical_or(other)
    
    bPositions = []
    newbits.each do |pos|
      bPositions << pos
    end
    
    positions.should == bPositions
  end
  
  it "should perform a logical and operation" do
    other = EwahBitset.new
    
    positions = []
    0.upto(5) do |i|
      @bitset.set(i * 10)
      positions << i * 10
    end
    
    5.upto(10) do |i|
      other.set(i * 10)
      positions << i * 10
    end
    
    newbits = @bitset.logical_and(other)
    
    bPositions = []
    newbits.each do |pos|
      bPositions << pos
    end
    
    (positions & bPositions).should == [50]
  end
  
  it "should serialize and deserialize" do
    0.upto(10) do |i|
      @bitset.set(i * 10)
    end

    newbits = EwahBitset.new.deserialize(@bitset.serialize)
    
    @bitset.should == newbits
  end
end
