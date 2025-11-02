// ============================================================
// LAB: Shift Register and Register Design
// ============================================================

// ============================================================
// Q1. Structural Verilog code for a 6-bit shift register
// ============================================================

// D Flip-Flop (Positive-edge triggered)
module d_ff (
    input clk,
    input D,
    output reg Q
);
    always @(posedge clk)
        Q <= D;
endmodule


// 6-bit Shift Register (Structural Implementation)
module shift_reg6 (
    input clk,
    input SI,           // Serial input
    output [5:0] Q
);
    wire [5:0] d;

    assign d[0] = SI;       // Shift input
    assign d[1] = Q[0];
    assign d[2] = Q[1];
    assign d[3] = Q[2];
    assign d[4] = Q[3];
    assign d[5] = Q[4];

    // Instantiate D Flip-Flops
    d_ff FF0 (.clk(clk), .D(d[0]), .Q(Q[0]));
    d_ff FF1 (.clk(clk), .D(d[1]), .Q(Q[1]));
    d_ff FF2 (.clk(clk), .D(d[2]), .Q(Q[2]));
    d_ff FF3 (.clk(clk), .D(d[3]), .Q(Q[3]));
    d_ff FF4 (.clk(clk), .D(d[4]), .Q(Q[4]));
    d_ff FF5 (.clk(clk), .D(d[5]), .Q(Q[5]));
endmodule


// ============================================================
// Q2. Verilog code for an N-bit register (parameterized)
// ============================================================

module n_bit_reg #(parameter N = 8) (
    input clk,
    input rst,
    input [N-1:0] D,
    output reg [N-1:0] Q
);
    always @(posedge clk) begin
        if (rst)
            Q <= 0;
        else
            Q <= D;
    end
endmodule


// ============================================================
// Q3. 4-bit Shift Register with Parallel Load
// Function Table:
// Shift Load | Operation
//   0    0   → Shift Left
//   0    1   → Load Parallel Data
//   1    0   → Complement
//   1    1   → No Change
// ============================================================

module shift_reg4_control (
    input clk,
    input Shift,
    input Load,
    input [3:0] P,    // Parallel input
    output reg [3:0] Q
);
    always @(posedge clk) begin
        case ({Shift, Load})
            2'b00: Q <= {Q[2:0], 1'b0}; // Shift left
            2'b01: Q <= P;              // Load parallel data
            2'b10: Q <= ~Q;             // Complement
            2'b11: Q <= Q;              // No change
            default: Q <= Q;
        endcase
    end
endmodule


// ============================================================
// END OF LAB FILE
// ============================================================



Lab 10

Q1
module counter_0_to_6 (
    input clk,
    input rst,
    output reg [2:0] Q   // Q[2]=C, Q[1]=B, Q[0]=A
);
    wire A, B, C;
    assign {C, B, A} = Q;

    // Derived JK inputs
    wire Ja = 1'b1;
    wire Ka = 1'b1;
    wire Jb = A;
    wire Kb = A;
    wire Jc = A & B;
    wire Kc = A & B;

    // JK flip-flop next state equations: Q⁺ = JQ' + K'Q
    wire nextA = (Ja & ~A) | (~Ka & A);
    wire nextB = (Jb & ~B) | (~Kb & B);
    wire nextC = (Jc & ~C) | (~Kc & C);

    // Sequential update
    always @(posedge clk or posedge rst) begin
        if (rst)
            Q <= 3'b000; // start at 0
        else if (Q == 3'b111)
            Q <= 3'b000; // force reset after 6
        else
            Q <= {nextC, nextB, nextA};
    end
endmodule





Q2
module counter_custom_sr (
    input clk,
    input rst,
    output reg [2:0] Q   // Q[2]=C, Q[1]=B, Q[0]=A
);
    wire A, B, C;
    assign {C, B, A} = Q;

    // Derive SR inputs (from state table simplification)
    // These are example logical relations for SR flip-flops
    // Next state = S + R'Q (SR characteristic)
    wire Sa = (~C & ~B) | (B & ~A);  // example simplified function
    wire Ra = (C & B & A);           // example reset condition
    wire Sb = (A & ~C);              
    wire Rb = (~A & C);
    wire Sc = (A & B);
    wire Rc = (~A & ~B & C);

    // Next state equations for SR: Q⁺ = S + R'Q
    wire nextA = Sa | (~Ra & A);
    wire nextB = Sb | (~Rb & B);
    wire nextC = Sc | (~Rc & C);

    always @(posedge clk or posedge rst) begin
        if (rst)
            Q <= 3'b001;   // start at 1
        else
            Q <= {nextC, nextB, nextA};
    end
endmodule

Q3
module counter_custom_t (
    input clk,
    input rst,
    output reg [2:0] Q   // Q[2]=C, Q[1]=B, Q[0]=A
);
    wire A, B, C;
    assign {C, B, A} = Q;

    // T flip-flop equation: Q⁺ = Q ⊕ T
    // T = 1 → toggle, T = 0 → hold

    // Derived T inputs based on sequence
    wire Ta = 1'b1;              // A toggles every step
    wire Tb = A | (C & ~B);      // example toggling condition
    wire Tc = (A & B) | (~A & ~B & C);

    // Next state equations
    wire nextA = A ^ Ta;
    wire nextB = B ^ Tb;
    wire nextC = C ^ Tc;

    always @(posedge clk or posedge rst) begin
        if (rst)
            Q <= 3'b000; // start at 0
        else
            Q <= {nextC, nextB, nextA};
    end
endmodule



// ============================================================
// LAB 3–6 : COMPLETE VERILOG LAB COLLECTION
// Includes:
//   Lab 3: Decoders & Encoders
//   Lab 4: Multiplexer-based and Decoder-based Implementations
//   Lab 5: Flip-Flops (Behavioral)
//   Lab 6: Registers & Shift Registers
// ============================================================


// ============================================================
// ======================= LAB 3 ===============================
// DECODERS & ENCODERS
// ============================================================

// ---------------- Q1 ----------------
// 2-to-4 Decoder with active-low enable and active-high outputs
module decoder_2to4 (
    input [1:0] A,
    input EN_n,           // active-low enable
    output reg [3:0] Y    // active-high outputs
);
    always @(*) begin
        if (!EN_n)
            Y = 4'b0000;   // disabled
        else begin
            if (A == 2'b00) Y = 4'b0001;
            else if (A == 2'b01) Y = 4'b0010;
            else if (A == 2'b10) Y = 4'b0100;
            else Y = 4'b1000;
        end
    end
endmodule


// ---------------- Q2 ----------------
// 4-to-16 Decoder using 2-to-4 decoders (active-high enable)
module decoder_4to16 (
    input [3:0] A,
    input EN,
    output [15:0] Y
);
    wire [3:0] en_low;

    assign en_low[0] = ~(EN & ~A[3] & ~A[2]);
    assign en_low[1] = ~(EN & ~A[3] &  A[2]);
    assign en_low[2] = ~(EN &  A[3] & ~A[2]);
    assign en_low[3] = ~(EN &  A[3] &  A[2]);

    decoder_2to4 D0 (.A(A[1:0]), .EN_n(en_low[0]), .Y(Y[3:0]));
    decoder_2to4 D1 (.A(A[1:0]), .EN_n(en_low[1]), .Y(Y[7:4]));
    decoder_2to4 D2 (.A(A[1:0]), .EN_n(en_low[2]), .Y(Y[11:8]));
    decoder_2to4 D3 (.A(A[1:0]), .EN_n(en_low[3]), .Y(Y[15:12]));
endmodule


// ---------------- Q3 ----------------
// 4-to-2 Priority Encoder using casex
module priority_encoder_4to2 (
    input [3:0] D,
    output reg [1:0] Y,
    output reg valid
);
    always @(*) begin
        casex (D)
            4'b1xxx: begin Y = 2'b11; valid = 1'b1; end
            4'b01xx: begin Y = 2'b10; valid = 1'b1; end
            4'b001x: begin Y = 2'b01; valid = 1'b1; end
            4'b0001: begin Y = 2'b00; valid = 1'b1; end
            default: begin Y = 2'b00; valid = 1'b0; end
        endcase
    end
endmodule


// ---------------- Q4 ----------------
// 16-to-4 Priority Encoder using for loop
module priority_encoder_16to4 (
    input [15:0] D,
    output reg [3:0] Y,
    output reg valid
);
    integer i;
    always @(*) begin
        Y = 4'b0000;
        valid = 1'b0;
        for (i = 15; i >= 0; i = i - 1) begin
            if (D[i] && !valid) begin
                Y = i[3:0];
                valid = 1'b1;
            end
        end
    end
endmodule



// ============================================================
// ======================= LAB 4 ===============================
// MULTIPLEXERS & DECODER IMPLEMENTATIONS
// ============================================================

// ---------------- Q1 ----------------
// F(A,B,C,D)=Σm(0,1,2,4,6,9,12,14) using 4:1 MUX
module mux4_F (
    input A, B, C, D,
    output F
);
    wire [3:0] I;

    assign I[0] = (~C & ~D) | (~C & D);
    assign I[1] = (~C & ~D) | (C & ~D);
    assign I[2] = (~C & D);
    assign I[3] = (~C & ~D) | (C & D);

    assign F = (A == 0 && B == 0) ? I[0] :
               (A == 0 && B == 1) ? I[1] :
               (A == 1 && B == 0) ? I[2] :
               I[3];
endmodule


// ---------------- Q2 ----------------
// 4-bit Gray to Binary Converter (using 8:1 MUX logic)
module gray_to_binary (
    input [3:0] G,
    output [3:0] B
);
    assign B[3] = G[3];
    assign B[2] = G[3] ^ G[2];
    assign B[1] = G[3] ^ G[2] ^ G[1];
    assign B[0] = G[3] ^ G[2] ^ G[1] ^ G[0];
endmodule


// ---------------- Q3 ----------------
// F(a,b,c,d)=Σm(2,3,4,5,6,7,10,11,12,15) using Decoder + OR gate
module decoder4_F (
    input a, b, c, d,
    output F
);
    wire [15:0] Y;

    assign Y[0]  = (~a & ~b & ~c & ~d);
    assign Y[1]  = (~a & ~b & ~c &  d);
    assign Y[2]  = (~a & ~b &  c & ~d);
    assign Y[3]  = (~a & ~b &  c &  d);
    assign Y[4]  = (~a &  b & ~c & ~d);
    assign Y[5]  = (~a &  b & ~c &  d);
    assign Y[6]  = (~a &  b &  c & ~d);
    assign Y[7]  = (~a &  b &  c &  d);
    assign Y[8]  = ( a & ~b & ~c & ~d);
    assign Y[9]  = ( a & ~b & ~c &  d);
    assign Y[10] = ( a & ~b &  c & ~d);
    assign Y[11] = ( a & ~b &  c &  d);
    assign Y[12] = ( a &  b & ~c & ~d);
    assign Y[13] = ( a &  b & ~c &  d);
    assign Y[14] = ( a &  b &  c & ~d);
    assign Y[15] = ( a &  b &  c &  d);

    assign F = Y[2] | Y[3] | Y[4] | Y[5] | Y[6] | Y[7] | Y[10] | Y[11] | Y[12] | Y[15];
endmodule


// ---------------- Q4 ----------------
// 3-input Majority Function using 2-to-4 Decoder
module majority_3input (
    input A, B, C,
    output F
);
    wire [3:0] Y;

    assign Y[0] = ~A & ~B;
    assign Y[1] = ~A &  B;
    assign Y[2] =  A & ~B;
    assign Y[3] =  A &  B;

    assign F = Y[3] | (Y[1] & C) | (Y[2] & C);
endmodule



// ============================================================
// ======================= LAB 5 ===============================
// FLIP-FLOPS (Behavioral Models)
// ============================================================

// ---------------- Q1 ----------------
// Positive edge-triggered D FF with synchronous active high reset
module d_ff_sync_reset (
    input clk,
    input rst,
    input D,
    output reg Q
);
    always @(posedge clk) begin
        if (rst)
            Q <= 1'b0;
        else
            Q <= D;
    end
endmodule


// ---------------- Q2 ----------------
// Negative edge-triggered T FF with synchronous active low reset
module t_ff_sync_reset (
    input clk,
    input rst_n,
    input T,
    output reg Q
);
    always @(negedge clk) begin
        if (!rst_n)
            Q <= 1'b0;
        else if (T)
            Q <= ~Q;
        else
            Q <= Q;
    end
endmodule


// ---------------- Q3 ----------------
// Positive edge-triggered JK FF with asynchronous active high reset
module jk_ff_async_reset (
    input clk,
    input rst,
    input J, K,
    output reg Q
);
    always @(posedge clk or posedge rst) begin
        if (rst)
            Q <= 1'b0;
        else begin
            case ({J, K})
                2'b00: Q <= Q;
                2'b01: Q <= 1'b0;
                2'b10: Q <= 1'b1;
                2'b11: Q <= ~Q;
            endcase
        end
    end
endmodule


// ---------------- Q4 ----------------
// Negative edge-triggered SR FF with asynchronous active low reset
module sr_ff_async_reset (
    input clk,
    input rst_n,
    input S, R,
    output reg Q
);
    always @(negedge clk or negedge rst_n) begin
        if (!rst_n)
            Q <= 1'b0;
        else begin
            case ({S, R})
                2'b00: Q <= Q;
                2'b01: Q <= 1'b0;
                2'b10: Q <= 1'b1;
                2'b11: Q <= 1'bx;
            endcase
        end
    end
endmodule



// ============================================================
// ======================= LAB 6 ===============================
// REGISTERS & SHIFT REGISTERS
// ============================================================

// ---------------- Q1 ----------------
// Structural Verilog code for 6-bit Shift Register

module d_ff6 (
    input clk,
    input D,
    output reg Q
);
    always @(posedge clk)
        Q <= D;
endmodule

module shift_reg6 (
    input clk,
    input SI,
    output [5:0] Q
);
    wire [5:0] d;
    assign d[0] = SI;
    assign d[1] = Q[0];
    assign d[2] = Q[1];
    assign d[3] = Q[2];
    assign d[4] = Q[3];
    assign d[5] = Q[4];

    d_ff6 FF0 (.clk(clk), .D(d[0]), .Q(Q[0]));
    d_ff6 FF1 (.clk(clk), .D(d[1]), .Q(Q[1]));
    d_ff6 FF2 (.clk(clk), .D(d[2]), .Q(Q[2]));
    d_ff6 FF3 (.clk(clk), .D(d[3]), .Q(Q[3]));
    d_ff6 FF4 (.clk(clk), .D(d[4]), .Q(Q[4]));
    d_ff6 FF5 (.clk(clk), .D(d[5]), .Q(Q[5]));
endmodule


// ---------------- Q2 ----------------
// N-bit Register
module n_bit_reg #(parameter N = 8) (
    input clk,
    input rst,
    input [N-1:0] D,
    output reg [N-1:0] Q
);
    always @(posedge clk) begin
        if (rst)
            Q <= 0;
        else
            Q <= D;
    end
endmodule


// ---------------- Q3 ----------------
// 4-bit Shift Register with Parallel Load & Control Table
module shift_reg4_control (
    input clk,
    input Shift,
    input Load,
    input [3:0] P,
    output reg [3:0] Q
);
    always @(posedge clk) begin
        case ({Shift, Load})
            2'b00: Q <= {Q[2:0], 1'b0}; // Shift left
            2'b01: Q <= P;              // Load parallel data
            2'b10: Q <= ~Q;             // Complement
            2'b11: Q <= Q;              // No change
        endcase
    end
endmodule


// ============================================================
// END OF LAB 3–6 FILE
// ============================================================
