import React, { useEffect, useState, useRef } from "react";
import SockJS from "sockjs-client";
import { Client } from "@stomp/stompjs";

const Chat = () => {
  const [messages, setMessages] = useState([]);
  const [input, setInput] = useState("");
  const stompClientRef = useRef(null);

  useEffect(() => {
   // const socket = new SockJS("http://localhost:8080/ws");
    const socket = new SockJS("http://chattest-env.eba-jraj8msr.eu-north-1.elasticbeanstalk.com/ws");
    const client = new Client({
      webSocketFactory: () => socket,
      reconnectDelay: 5000,
      onConnect: () => {
        console.log("Connected to WebSocket");
        client.subscribe("/topic/messages", (message) => {
          const payload = JSON.parse(message.body);
          setMessages((prev) => [...prev, payload]);
        });
      },
      onStompError: (frame) => {
        console.error("Broker error:", frame.headers["message"]);
      },
    });

    client.activate();
    stompClientRef.current = client;

    return () => {
      client.deactivate();
    };
  }, []);

  const sendMessage = () => {
    if (!input.trim()) return;
    stompClientRef.current.publish({
      destination: "/app/send",
      body: JSON.stringify({
        content: input,
        sender: "ReactUser",
      }),
    });
    setInput("");
  };

  return (
    <div style={{ width: 400, margin: "20px auto", fontFamily: "system-ui, sans-serif" }}>
      <h3 style={{ margin: "0 0 16px 0" }}>💬 Chat</h3>

      <div
        style={{
          border: "1px solid #ddd",
          height: 340,
          overflowY: "auto",
          padding: "12px",
          background: "#f9f9f9",
          borderRadius: "8px",
          marginBottom: 16,
          display: "flex",
          flexDirection: "column",
          gap: 10,
        }}
      >
        {messages.map((msg, i) => (
          <div
            key={i}
            style={{
              alignSelf: msg.sender === "ReactUser" ? "flex-end" : "flex-start",
              maxWidth: "80%",
              padding: "10px 14px",
              borderRadius: "18px",
              background: msg.sender === "ReactUser" ? "#0084ff" : "#e5e5ea",
              color: msg.sender === "ReactUser" ? "white" : "#000",
              wordBreak: "break-word",
              fontSize: "15px",
              lineHeight: 1.4,
            }}
          >
            <div style={{ fontSize: "0.82em", opacity: 0.85, marginBottom: 3 }}>
              {msg.sender}
            </div>
            <div>{msg.content}</div>
          </div>
        ))}
      </div>

      <div style={{ display: "flex", gap: 8 }}>
        <input
          value={input}
          onChange={(e) => setInput(e.target.value)}
          onKeyDown={(e) => e.key === "Enter" && sendMessage()}
          placeholder="Type a message..."
          style={{
            flex: 1,
            padding: "10px 12px",
            border: "1px solid #ccc",
            borderRadius: "20px",
            fontSize: "15px",
          }}
        />
        <button
          onClick={sendMessage}
          style={{
            padding: "10px 20px",
            background: "#0084ff",
            color: "white",
            border: "none",
            borderRadius: "20px",
            fontWeight: 500,
            cursor: "pointer",
          }}
        >
          Send
        </button>
      </div>
    </div>
  );
};

export default Chat;