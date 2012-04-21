require 'lib/ewahbitset'

describe "An EwahBitset" do
  before(:each) do
    @bitset = EwahBitset.new
  end
  
  it "should initialize and set bits" do
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
  end
  
  it "should compare properly" do
    @other = EwahBitset.new
    
    0.upto(10) do |i|
      @bitset.set(i * 10)
      @other.set(i * 10)
    end
    
    @bitset.should == @other
  end
  
  it "should serialize and deserialize" do
    0.upto(10) do |i|
      @bitset.set(i * 10)
    end
    
    newbits = EwahBitset.new.deserialize(@bitset.serialize)
    
    @bitset.should == newbits
  end
end
