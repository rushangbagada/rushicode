import { useState, useCallback } from 'react'
import reactLogo from './assets/react.svg'
import viteLogo from '/vite.svg'
import './App.css'

function App() {
  const [length, setlength] = useState(6)
  const [numaloud, setnumaloud] = useState("false")
  const [charaloud, setcharaloud] = useState("false")
  const [password, setpassword] = useState("")

  const passwordgenerator = useCallback(() => {
    let pass = ""
    let str = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz"
    if (numaloud) {
      str += "0123456789"
    }
    if (charaloud) {
      str += "!@#$%^&*()_+"
    }
    for (let i = 0; i < length; i++) {
      pass += str.charAt(Math.floor(Math.random() * str.length + 1))
    }
    setpassword(pass)
  }, [length, numaloud, charaloud, setpassword])

  const copy = useCallback(() => {
    navigator.clipboard.writeText(password)
  }, [password])

  return (
    <div className="bg-slate-900 h-[100vh] flex justify-center items-center ">
      <div className="flex bg-slate-600 p-10  flex-col justify-center w-fit items-center h-fit rounded-2xl">
        <h1 className="text-white text-2xl pb-7">Password generator</h1>
      
        <div className="mb-4 w-full flex justify-between">
          <input className="w-[300px] bg-white py-2 px-4 rounded-lg" readOnly={true} type="text" value={password} />
          <button onClick={copy} className="text-white rounded-lg px-4 py-2 bg-slate-700">copy</button>
        </div>
        <div className="flex  justify-around items-center">
          <input
            className="bg-white" type="range" min="6" max="100"
           onChange={(e) => setlength(e.target.value)}/>
          <label  className="text-white px-3 ">{length}</label>
          <input
            defaultChecked={charaloud}
            onChange={() => setcharaloud((charaloud)=>!charaloud) }
            type="checkbox" name="" id="" />
          <label className="text-white px-3" htmlFor="">characters</label>
          <input
            defaultChecked={numaloud}
            onChange={() => setnumaloud((numaloud)=>!numaloud) }
            type="checkbox" name="" id="" />
          <label className="text-white px-3" htmlFor=""> numbers</label>
        </div>
        <button onClick={passwordgenerator} className="text-white rounded-lg px-4 py-4 mt-4 mb-0 bg-slate-700">Generate</button>
      </div>
    </div>
  )
}

export default App















